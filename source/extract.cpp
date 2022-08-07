#include <minizip/unzip.h>
#include <string>
#include <string.h>
#include <dirent.h>

#include "extract.hpp"
#include "progress_event.hpp"

constexpr size_t WRITE_BUFFER_SIZE = 0x1000000;

namespace extract {
    int unzip(const std::string &file, const std::string &output) {
        chdir(output.c_str());
        unzFile zfile = unzOpen(file.c_str());
        unz_global_info gi = {0};
        unzGetGlobalInfo(zfile, &gi);

        ProgressEvent::instance().setTotalSteps(gi.number_entry);
        ProgressEvent::instance().setStep(0);

        for (int i = 0; i < gi.number_entry; ++i) {
            char filename_inzip[0x301] = {0};
            unz_file_info file_info = {0};
            unzOpenCurrentFile(zfile);
            unzGetCurrentFileInfo(zfile, &file_info, filename_inzip, sizeof(filename_inzip), NULL, 0, NULL, 0);
            std::string filename_inzip_s = filename_inzip;

            if (filename_inzip[strlen(filename_inzip) - 1] == '/') {
                DIR *dir = opendir(filename_inzip);
            }

            else {
                FILE *outfile;
                void *buf = malloc(WRITE_BUFFER_SIZE);

                if ((filename_inzip_s == "atmosphere/package3") || (filename_inzip_s == "switch/AtmoPackUpdater.nro") || (filename_inzip_s == "atmosphere/stratosphere.romfs")) {
                    outfile = fopen((filename_inzip_s + ".temp").c_str(), "wb");
                }

                else {
                    outfile = fopen(filename_inzip, "wb");
                }
                for (int j = unzReadCurrentFile(zfile, buf, WRITE_BUFFER_SIZE); j > 0; j = unzReadCurrentFile(zfile, buf, WRITE_BUFFER_SIZE)) {
                    fwrite(buf, 1, j, outfile);
                }
    
                fclose(outfile);
                free(buf);
            }

            ProgressEvent::instance().incrementStep(1);
            unzCloseCurrentFile(zfile);
            unzGoToNextFile(zfile);
        }
        
        unzClose(zfile);
        remove(file.c_str());
        ProgressEvent::instance().setStep(ProgressEvent::instance().getMax());

        return 0;
    }
}