#pragma once

#include <vector>
#include <string>

//for the file update_tab.hpp
enum class contentType
{
    ams_cfw,
    app,
    firmwares,
    sigpatches,
    homebrew,
};

struct homebrew_label {
    std::string title;
    std::string url;
    std::string version;
    bool homebrew;
};

const std::vector<std::string> contentSettings = {"dns", "theme", "clear", "reboot", "auto-update"};


const std::string APP_VER = "2.0.1"; 
constexpr std::string_view contentTypeNames[5]{"ams_cfw", "app", "firmwares", "sigpatches", "homebrew"};

//app path
const std::string GOOD_APP_PATH =         "/switch/AtmoPackUpdater/AtmoPackUpdater.nro";
const std::string BAD_APP_PATH =          "/switch/AtmoPackUpdater.nro";

//Path for the download
const std::string NRO_PATH =              "/switch/AtmoPackUpdater/AtmoPackUpdater.nro";
const std::string AMS_DOWNLOAD_PATH =     "/config/AtmoPackUpdater/ams.zip";
const std::string SYSMODULES_DOWNLOAD_PATH= "/config/AtmoPackUpdater/sysmodules.zip";
const std::string SIG_DOWNLOAD_PATH =     "/config/AtmoPackUpdater/sig.zip";
const std::string FIR_DOWNLOAD_PATH =     "/config/AtmoPackUpdater/fir.zip";
const std::string APP_DOWNLOAD_PATH =     "/config/AtmoPackUpdater/app.nro";
const std::string DOWNLOAD_PATH =         "/config/AtmoPackUpdater/";
const std::string FORWARDER_PATH =        "/config/AtmoPackUpdater/amssu-forwarder.nro";
const std::string DAYBREAK_PATH =         "/switch/daybreak.nro";
const std::string FIRMWARE_PATH =         "/firmware/";   

const std::string ROMFS_FORWARDER =       "romfs:/forwarder/amssu-forwarder.nro";

//PATH
const std::string AMS_PATH =              "/atmosphere/";

const std::string CONTENTS_PATH =         "contents/";
const std::string SWITCH_PATH =           "/switch/";
const std::string ROOT =                  "/";

//URL for the JSON file
const std::string NXLINKS_URL =           "https://codeberg.org/Zoria/AtmoPack-Vanilla/raw/commit/622abc8703649e876558e7676eb9384d4f326efa/download/nx-links-new.json";
const std::string APP_URL =               "https://github.com/Zoria/AtmoPackUpdater/releases/latest/download/AtmoPackUpdater.nro";
