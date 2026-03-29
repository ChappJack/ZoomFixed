#include "settings.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

// The toggle-menu keybind is now declared in mod.json under "toggle_menu" as of Geode 5.0.0

SettingsManager* SettingsManager::get() {
	static auto inst = new SettingsManager;
	return inst;
}

void SettingsManager::init() {
#ifdef GEODE_IS_DESKTOP
	autoHideMenu = Mod::get()->getSettingValue<bool>("auto-hide-menu");
	listenForSettingChanges<bool>("auto-hide-menu", [&](bool enable) {
		autoHideMenu = enable;
	});

	autoShowMenu = Mod::get()->getSettingValue<bool>("auto-show-menu");
	listenForSettingChanges<bool>("auto-show-menu", [&](bool enable) {
		autoShowMenu = enable;
	});

	altDisablesZoom = Mod::get()->getSettingValue<bool>("alt-disables-zoom");
	listenForSettingChanges<bool>("alt-disables-zoom", [&](bool enable) {
		altDisablesZoom = enable;
	});

	zoomSensitivity = Mod::get()->getSettingValue<float>("zoom-sensitivity");
	listenForSettingChanges<float>("zoom-sensitivity", [&](float sensitivity) {
		zoomSensitivity = sensitivity;
	});
#endif // GEODE_IS_DESKTOP
}
