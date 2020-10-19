#include "accent.hpp"

#include <winrt/Windows.UI.ViewManagement.h>
#include <iostream>

using namespace std;

namespace rt_vm = winrt::Windows::UI::ViewManagement;

tuple<int, int, int> getAccentColor() {
    winrt::init_apartment();
    auto color = rt_vm::UISettings::UISettings().GetColorValue(rt_vm::UIColorType::Accent);

    return make_tuple((int) color.R, (int) color.G, (int) color.B);
}