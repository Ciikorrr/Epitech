#ifndef MEMORY_HPP
#define MEMORY_HPP
#include <cstddef>
#include <list>
#include <optional>

#include "../../Ui/Widgets/WidgetStack.hpp"
#include "../Module.hpp"

class Module::Memory final : public BaseModule {
   public:
    Memory(bool enabled) : BaseModule(enabled){};
    ~Memory() override = default;

    std::optional<std::size_t> getMemTotalKB() const;
    std::optional<std::size_t> getMemFreeKB() const;
    std::optional<std::size_t> getMemAvailableKB() const;
    std::optional<std::size_t> getSwapTotalKB() const;
    std::optional<std::size_t> getSwapFreeKB() const;
    WidgetStack getWidgets() override;

    void retrieveMemoryInfos();

    void update() override;

    void printMemInfoList() const;
    static size_t stringToSizeT(const std::string& str);

    std::string getIdentifier() const override;
    std::string getDisplayName() const override;

   private:
    std::optional<std::size_t> _memTotalKB{};
    std::optional<std::size_t> _memFreeKB{};
    std::optional<std::size_t> _memAvailableKB{};
    std::optional<std::size_t> _swapTotalKB{};
    std::optional<std::size_t> _swapFreeKB{};
    std::list<std::string> _memeInfoContent{};
};

#endif  // MEMORY_HPP
