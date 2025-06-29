load("@rules_cc//cc:defs.bzl", "cc_binary")


cc_binary(
    name = "main",
    srcs = ["main.cpp", 
            "gossip_config.h", 
            "gossip_config.cpp",
            "gossip_manager.h",
            "gossip_manager.cpp",
            "gossip_sender.cpp",
            "sender.h",
            "receiver.h",
            "gossip_receiver.cpp"
            ],
    deps = [
        "@jsoncpp//:jsoncpp",
    ],
)