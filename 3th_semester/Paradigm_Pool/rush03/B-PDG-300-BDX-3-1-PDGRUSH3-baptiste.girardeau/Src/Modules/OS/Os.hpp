#ifndef OS_HPP
#define OS_HPP

#include <optional>
#include <string>

#include "../Module.hpp"

class Module::OS final : public BaseModule {
   public:
    OS(bool enabled) : BaseModule(enabled){};
    ~OS() override = default;

    void update() override;
    WidgetStack getWidgets() override;

    std::string getIdentifier() const override;
    std::string getDisplayName() const override;

   private:
    std::optional<std::string> getOsName();
    std::optional<std::string> getKernelVersion();

    std::optional<std::string> _osName;
    std::optional<std::string> _kernelVersion;
};

#endif  // OS_HPP
