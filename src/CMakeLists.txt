set( debinstaller_SRCS
    main.cpp
    debinstallerwindow.cpp
)

ki18n_wrap_ui(debinstaller_SRCS debinstaller.ui)

add_executable( debinstaller ${debinstaller_SRCS} )

target_link_libraries( debinstaller
    KF5::CoreAddons
    KF5::I18n
    Qt5::Widgets
)

install( TARGETS debinstaller ${KDE_INSTALL_TARGETS_DEFAULT_ARGS} )
install( PROGRAMS org.example.debinstaller.desktop DESTINATION ${KDE_INSTALL_APPDIR} )
install( FILES org.example.debinstaller.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR} )
