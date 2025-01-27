#include <catch2/catch_all.hpp>

#include <cppcolormap.h>

TEST_CASE("cppcolormap::colormap", "cppcolormap.h")
{
    std::vector<std::string> cmaps{
        "Accent",
        "Dark2",
        "Paired",
        "Spectral",
        "Pastel1",
        "Pastel2",
        "Set1",
        "Set2",
        "Set3",
        "Blues",
        "Greens",
        "Greys",
        "Oranges",
        "Purples",
        "Reds",
        "BuPu",
        "GnBu",
        "PuBu",
        "PuBuGn",
        "PuRd",
        "RdPu",
        "OrRd",
        "RdOrYl",
        "YlGn",
        "YlGnBu",
        "YlOrRd",
        "BrBG",
        "PuOr",
        "RdBu",
        "RdGy",
        "RdYlBu",
        "RdYlGn",
        "PiYG",
        "PRGn",
        "spring",
        "summer",
        "autumn",
        "winter",
        "bone",
        "cool",
        "hot",
        "copper",
        "hsv",
        "nipy_spectral",
        "jet",
        "terrain",
        "seismic",
        "afmhot",
        "magma",
        "inferno",
        "plasma",
        "viridis",
        "Accent_r",
        "Dark2_r",
        "Paired_r",
        "Spectral_r",
        "Pastel1_r",
        "Pastel2_r",
        "Set1_r",
        "Set2_r",
        "Set3_r",
        "Blues_r",
        "Greens_r",
        "Greys_r",
        "Oranges_r",
        "Purples_r",
        "Reds_r",
        "BuPu_r",
        "GnBu_r",
        "PuBu_r",
        "PuBuGn_r",
        "PuRd_r",
        "RdPu_r",
        "OrRd_r",
        "RdOrYl_r",
        "YlGn_r",
        "YlGnBu_r",
        "YlOrRd_r",
        "BrBG_r",
        "PuOr_r",
        "RdBu_r",
        "RdGy_r",
        "RdYlBu_r",
        "RdYlGn_r",
        "PiYG_r",
        "PRGn_r",
        "spring_r",
        "summer_r",
        "autumn_r",
        "winter_r",
        "bone_r",
        "cool_r",
        "hot_r",
        "copper_r",
        "hsv_r",
        "nipy_spectral_r",
        "jet_r",
        "terrain_r",
        "seismic_r",
        "afmhot_r",
        "magma_r",
        "inferno_r",
        "plasma_r",
        "viridis_r",
        "White",
        "Grey",
        "Black",
        "Red",
        "Blue",
        "tuewarmred",
        "tuedarkblue",
        "tueblue",
        "tuelightblue",
        "Apricot",
        "Aquamarine",
        "Bittersweet",
        "BlueGreen",
        "BlueViolet",
        "BrickRed",
        "Brown",
        "BurntOrange",
        "CadetBlue",
        "CarnationPink",
        "Cerulean",
        "CornflowerBlue",
        "Cyan",
        "Dandelion",
        "DarkOrchid",
        "Emerald",
        "ForestGreen",
        "Fuchsia",
        "Goldenrod",
        "Gray",
        "Green",
        "GreenYellow",
        "JungleGreen",
        "Lavender",
        "LimeGreen",
        "Magenta",
        "Mahogany",
        "Maroon",
        "Melon",
        "MidnightBlue",
        "Mulberry",
        "NavyBlue",
        "OliveGreen",
        "Orange",
        "OrangeRed",
        "Orchid",
        "Peach",
        "Periwinkle",
        "PineGreen",
        "Plum",
        "ProcessBlue",
        "Purple",
        "RawSienna",
        "RedOrange",
        "RedViolet",
        "Rhodamine",
        "RoyalBlue",
        "RoyalPurple",
        "RubineRed",
        "Salmon",
        "SeaGreen",
        "Sepia",
        "SkyBlue",
        "SpringGreen",
        "Tan",
        "TealBlue",
        "Thistle",
        "Turquoise",
        "Violet",
        "VioletRed",
        "WildStrawberry",
        "Yellow",
        "YellowGreen",
        "YellowOrange"};

    for (auto& cmap : cmaps) {
        auto c = cppcolormap::colormap(cmap);
        REQUIRE(xt::amin(c)() >= 0.0);
        REQUIRE(xt::amax(c)() <= 1.0);
    }
}

TEST_CASE("cppcolormap::as_colors", "cppcolormap.h")
{
    auto c = cppcolormap::Greys(5);
    xt::xtensor<double, 1> data = xt::arange<double>(c.shape(0));
    auto m = cppcolormap::as_colors(data, c);
    REQUIRE(xt::allclose(c, m));
}
