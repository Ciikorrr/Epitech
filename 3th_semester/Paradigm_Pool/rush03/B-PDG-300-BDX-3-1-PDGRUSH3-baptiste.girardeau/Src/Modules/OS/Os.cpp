#include "Os.hpp"

#include <sys/utsname.h>

#include <optional>
#include <sstream>

#include "../../Parse/FileParser.hpp"

constexpr const char *OS_RELEASE_FILE = "/etc/os-release";

std::string Module::OS::getDisplayName() const {
    return "Os informations";
}

std::string Module::OS::getIdentifier() const {
    return "os";
}

void Module::OS::update() {
    if (!_osName.has_value()) {
        _osName = getOsName();
    }

    if (!_kernelVersion.has_value()) {
        _kernelVersion = getKernelVersion();
    }
}

WidgetStack Module::OS::getWidgets() {
    WidgetStack stack("OS information", this->getIdentifier());

    stack.registerWidget(
        std::make_unique<TextWidget>("OS Name", _osName.value_or("Unknown"),
                                     TextWidget::colorFrom(_osName)));

    stack.registerWidget(std::make_unique<TextWidget>(
        "Kernel Version", _kernelVersion.value_or("Unknown"),
        TextWidget::colorFrom(_kernelVersion)));

    return stack;
}

std::optional<std::string> Module::OS::getOsName() {
    FileParser parser = FileParserBuilder(OS_RELEASE_FILE)
                            .setDelimiter('=')
                            .valueHasQuotes(true)
                            .parse();

    return parser.get("PRETTY_NAME");
}

std::optional<std::string> Module::OS::getKernelVersion() {
    struct utsname buffer;
    if (uname(&buffer) != 0) {
        return std::nullopt;
    }

    std::ostringstream output;
    output << buffer.sysname << " " << buffer.release;

    return output.str();
}
