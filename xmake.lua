add_rules("mode.debug", "mode.release")

add_requires("spdlog", "nlohmann_json", "ffmpeg")
target("StreamWatchServer")
    set_kind("binary")
    add_files("src/*.cpp")
    add_packages("spdlog", "nlohmann_json", "ffmpeg")

-- xmake project -k vsxmake -m "debug,release"
