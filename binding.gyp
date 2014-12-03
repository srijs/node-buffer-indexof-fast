{
  "targets": [
    {
      "target_name": "indexof",
      "sources": [
        "indexof.cc"
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}
