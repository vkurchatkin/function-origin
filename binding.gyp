{
  "targets": [
    {
      "target_name": "function_origin",
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],
      "sources": [
        "src/function_origin.cc"
      ]
    }
  ]
}
