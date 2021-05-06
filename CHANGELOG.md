
# Change Log

All notable changes to this project will be documented in this file.  The format is based on [Keep a Changelog](http://keepachangelog.com/), and this project adheres to [Semantic Versioning](http://semver.org/).

## <unreleased> [0.1.1] - 2021-05-05

Updated to comply with the Arduio 1.5 standard directory structure.  [Library Manager FAQ · arduino_Arduino Wiki](https://github.com/arduino/Arduino/wiki/Library-Manager-FAQ).

Library can now be installed From the Arduino IDO, by going to `File > XX`

### Added
- Initial `README.md` file, for GitHub and user documentation.
- `library.projects` file now allows the project repo (on GitHub) to be scanned by Arduino, and automatically added to the Library Manager.
- Added version number (in `library.projects` file), and the `CHANGELOG.md` (this file)

### Changed
- Directory structure is now compatible with the latest [Library specification - Arduino CLI](https://arduino.github.io/arduino-cli/latest/library-specification/) (rev.2.2).
- Source files (`.h` and `.cpp`) are now in the `/src` directory

## [0.1.0] - 2015-01-11

Initial code release.  

### Added
- Initial commit of the code.
- Added Apache 2.0 License