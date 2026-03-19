# Activity 1 Report Template

## Student Information
- Name:
- Student ID:
- Course/Section:
- Date:

## Repository Structure
```
activity1/
├── README.md
├── screenshots/
├── task1/
│   ├── file_creator_lib.c
│   ├── file_creator_sys.c
│   ├── file_reader_lib.c
│   ├── file_reader_sys.c
│   └── file_creator_win.c   (optional bonus)
└── task2/
		├── dir_list_lib.c
		└── dir_list_sys.c
```

## Task 1: File Creation and Reading

### 1.1 Library vs System Call Implementations
- `file_creator_lib.c`: Summary of implementation
- `file_creator_sys.c`: Summary of implementation
- `file_reader_lib.c`: Summary of implementation
- `file_reader_sys.c`: Summary of implementation

### 1.2 Build Commands
```bash
cd task1
gcc -Wall -Wextra -o file_creator_lib file_creator_lib.c
gcc -Wall -Wextra -o file_creator_sys file_creator_sys.c
gcc -Wall -Wextra -o file_reader_lib file_reader_lib.c
gcc -Wall -Wextra -o file_reader_sys file_reader_sys.c
```

### 1.3 Execution Screenshots
- Creator (library): `screenshots/task1_creator_lib.png`
- Creator (system): `screenshots/task1_creator_sys.png`
- Reader (library): `screenshots/task1_reader_lib.png`
- Reader (system): `screenshots/task1_reader_sys.png`

### 1.4 strace Analysis
- Screenshot(s): `screenshots/strace_*.png`
- Observations:
	- Which syscalls are used by each executable?
	- Similarities and differences between library and direct syscall versions.

## Task 2: Directory Listing

### 2.1 Library vs System Call Implementations
- `dir_list_lib.c`: Summary of implementation
- `dir_list_sys.c`: Summary of implementation

### 2.2 Build Commands
```bash
cd task2
gcc -Wall -Wextra -o dir_list_lib dir_list_lib.c
gcc -Wall -Wextra -o dir_list_sys dir_list_sys.c
```

### 2.3 Execution Screenshots
- Library version: `screenshots/task2_lib.png`
- System-call version: `screenshots/task2_sys.png`

## Task 4: System Information and OS Layers

### 4.1 System Information Screenshot
- `screenshots/task4_system_info.png`

### 4.2 OS Layers Diagram
- `screenshots/task4_os_layers_diagram.png`

## Reflection
1. What did you learn about the difference between C library wrappers and direct syscalls?
2. Which approach was easier to write and debug, and why?
3. What did `strace` reveal that surprised you?
4. Challenges faced and how you solved them.

## Notes
- Keep all screenshots inside `screenshots/`.
- Update this report with your own observations and outputs.
