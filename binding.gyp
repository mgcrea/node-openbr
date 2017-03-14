{
  "targets": [{
    "target_name": "openbr",
    "sources": [
      "src/openbr.cc"
    ],
    "include_dirs": [
      "<!(node -e \"require('nan')\")"
    ],
    "conditions": [
      ["OS=='linux'", {
        "cflags": [
          "<!@(pkg-config --cflags opencv Qt5Core)"
        ],
        "ldflags": [
          "<!@(pkg-config --libs-only-L --libs-only-other opencv Qt5Core)"
        ],
        "libraries": [
          "-lopenbr",
          "<!@(pkg-config --libs-only-l opencv Qt5Core)"
        ]
      }]
    ]
  }]
}
