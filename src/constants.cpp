#include "constants.h"

#define STR(x) #x

#define STRINGIFY(x) STR(x)
#define CONCAT(x,y)  STR(x##y)


const char *Constants::VERSION = STRINGIFY(APP_VERSION);
const char *Constants::APP_NAME = "MediaPort";
const char *Constants::DOMAIN_NAME = "mediaport.org";
const char *Constants::WEBSITE = "http://www.mediaport.org/app";
const char *Constants::EMAIL = "info@mediaport";

const char *Constants::UPDATE_PATH = "http://www.mediaport.org/app/update.pl?";
const char *Constants::PLAYLIST_PATH = "http://www.mediaport.org/app/json.pl?";
const char *Constants::LOGIN_PATH = "http://www.mediaport.org/app/login.pl?";
const char *Constants::REGISTER_PATH = "http://www.mediaport.org/app/register.pl?";


const char *Constants::PLUGIN_DIR = "/plugins/";

