# Vulnerable Port Scanner

A C++ network security tool designed to scan for open vulnerable ports on local or remote systems.

## Features

- Scan local system or remote IP addresses
- Configurable port range scanning
- Vulnerable port detection using predefined port list
- Automatic logging of discovered vulnerable ports
- Simple command-line interface

## Prerequisites

- C++ compiler (g++, clang++, etc.)
- Linux/Unix environment (uses POSIX socket libraries)
- Root/administrator privileges may be required for certain port operations

## Dependencies

The tool requires the following header files to be present in the `files/` directory:
- `files/ipaddr.h` - Contains the `ipaddre()` function for local IP detection
- `files/logfile.h` - Contains the `create_file()` function for logging results
- `files/vulnerable_ports.txt` - Text file containing list of known vulnerable port numbers (one per line)

## Compilation

```bash
g++ -o port-scan port-scan.cpp
```

## Usage

1. Run the compiled executable:
```bash
./port-scan
```

2. Follow the interactive prompts:
   - Choose option 1 to scan your local system
   - Choose option 2 to scan a remote IP address
   - Enter the starting port number for the scan range
   - Enter the ending port number for the scan range

3. The tool will scan the specified port range and log any discovered vulnerable ports to files in the program directory.

## File Structure

```
project/
├── port-scan.cpp          # Main source code
├── port-scan              # Compiled executable
└── files/
    ├── ipaddr.h           # Local IP address detection
    ├── logfile.h          # Logging functionality
    └── vulnerable_ports.txt # List of vulnerable ports
```

## Sample vulnerable_ports.txt Format

```
21
22
23
25
53
80
110
143
443
993
995
```

## Security Considerations

⚠️ **Important Security Notice:**
- This tool is intended for educational purposes and authorized security testing only
- Only scan systems you own or have explicit permission to test
- Unauthorized port scanning may violate laws and regulations
- Use responsibly and in compliance with your local laws and organizational policies

## Output

- The tool creates log files for each vulnerable port discovered
- Files are saved in the program directory
- Console output provides status updates during scanning

## Limitations

- Currently supports IPv4 addresses only
- TCP port scanning only (no UDP support)
- Basic connection-based detection (no service fingerprinting)
- Requires vulnerable port list to be manually maintained

## Troubleshooting

**"Vulnerable port file not found" error:**
- Ensure `files/vulnerable_ports.txt` exists and is readable
- Check file path and permissions

**"Error creating socket" error:**
- May require elevated privileges
- Check system socket limits and firewall settings

**"Invalid Input" errors:**
- Ensure port numbers are valid (1-65535)
- Verify IP address format is correct

## Contributing

To contribute to this project:
1. Ensure any modifications maintain security best practices
2. Test thoroughly in controlled environments
3. Update documentation for any new features
4. Follow responsible disclosure practices

## License

This tool is provided for educational and authorized testing purposes only. Users are responsible for ensuring compliance with applicable laws and regulations.

## Disclaimer

The authors are not responsible for any misuse of this tool. This software is provided "as is" without warranty of any kind. Users assume all risks associated with its use.