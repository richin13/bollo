#ifndef ASSETS
#define ASSETS

#include <QString>

namespace Ui {

/**
 * Path alias were all the GUI resources
 * are located images, sounds, gifs, etc.
 */
static QString ASSETS_PATH = ":/images/assets";

static QString DONE_ICON = ASSETS_PATH + "/check-icon.png";
static QString LOADING_GIFF_DARK = ASSETS_PATH + "/loadDark.GIF";
static QString DEFAULT_ICON = ASSETS_PATH + "/pending-icon.png";
static QString SHOP_ICON = ASSETS_PATH + "/shop-icon.png";
static QString AVATAR_ICON = ASSETS_PATH + "/avatar.png";
}

#endif // ASSETS

