#define CATCH_CONFIG_RUNNER
#include "third_party/catch2/catch.hpp"

#include "test/integration/resource_dir.h"

#include <QApplication>
#include <QDir>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Catch::Session session;

    std::string resourceDirString;

    // Build a new parser on top of Catch's
    using namespace Catch::clara;
    auto cli =
        session.cli() // Get Catch's composite command line parser
        | Opt(resourceDirString, "directory")["-w"]["--work-dir"](
              "The test directory which contains reference NFO files, etc."); // description string for the help output

    session.cli(cli);

    const int returnCode = session.applyCommandLine(argc, argv);
    if (returnCode != 0) {
        return returnCode;
    }

    if (resourceDirString.empty()) {
        std::cerr << "Missing resource directory argument!";
        return 1;
    }

    QDir resourceDir(resourceDirString.c_str());
    if (!resourceDir.exists()) {
        std::cerr << "Resource directory does not exist!";
        return 1;
    }
    if (!resourceDir.isReadable()) {
        std::cerr << "Resource directory is not readable!";
        return 1;
    }

    setResourceDir(resourceDir);

    return session.run();
}
