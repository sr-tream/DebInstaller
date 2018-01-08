set(debinstaller_ICONS
  16-apps-debinstaller.png
  22-apps-debinstaller.png
  32-apps-debinstaller.png
  48-apps-debinstaller.png
)

ecm_install_icons(ICONS ${debinstaller_ICONS} DESTINATION ${KDE_INSTALL_ICONDIR} THEME hicolor)
