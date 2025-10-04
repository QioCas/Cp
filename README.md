# Competitive Programming Workplace

This is a template / personal setup for competitive programming. 

## Directory Structure

```
├── bin/
│   └── configs/        
│       └── config.yaml # configuration files
│   └── source/         # support to create problem(s); and utility functions
│       └── make.py
│       └── util.py
│   └── check            # local test
│   └── stress           # stress test
│   └── new              # create new problem or create multiple problems
│   └── compile          # compile c++ code
├── Lib/                  # personal library
├── Stress/               # stress's directory
├── README.md              # this file
├── requirements.txt       # dependencies
```

## Getting Started
1. Clone this repository
2. Customize the files in `bin/`
## Usage

Compile C++ code:
```bash
compile file.cpp
```

Create new problem or multiple problems:
```bash
new [-h] [-t TEMPLATE] [-c] [-cur] [-n NUMPROBS] name
```

Run stress tests:
```bash
stress [-h] [-n NUMTEST] [-c]
```

Run local test:
```bash
check [-h] [-c]
```
