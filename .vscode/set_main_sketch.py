#!/usr/bin/env python3
# Copied to /usr/local/bin/set_main_sketch

import sys
import os
import json

ARDUINO_CONFIG_FILE = '.vscode/arduino.json'


if len(sys.argv) == 3:

    workspace_root = sys.argv[1]
    relative_file = sys.argv[2]
    config_file = os.path.join(workspace_root, ARDUINO_CONFIG_FILE)

    with open(config_file, 'r') as fp:
        arduino_config = json.load(fp)
        arduino_config['sketch'] = relative_file        
        with open(config_file, 'w') as fp:
            json.dump(arduino_config, fp, indent=4, sort_keys=True)