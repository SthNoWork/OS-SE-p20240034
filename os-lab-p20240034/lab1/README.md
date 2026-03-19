# Lab 1 — Linux Operating System Fundamentals

**Student ID:** p20240034
**Course:** Operating Systems
**Lab Reference:** [lab1-instruction.md](https://github.com/RathpiseyAlpha/ITC-OS-2026/blob/main/labs/lab1/lab1-instruction.md)

---

## Tasks

- [Task 1](#task-1--os-information)
-  [Task 2](#task-2--file-system-commands)
-  [Task 3](#task-3--package-management-with-apt)
-  [Task 4](#task-4--programs-vs-processes)
-  [Task 5](#task-5--installing-applications--multitasking)
-  [Task 6](#task-6--virtualization-detection)

---

## Commands covered

## `uname -a`
shows your kernel name, version, and system architecture
- example: `uname -a > task1_os_info.txt`

---

## `lsb_release -a`
shows your linux distro name, version, codename
- example: `lsb_release -a >> task1_os_info.txt`

---

## `pwd`
prints the folder you're currently in
- example: `pwd`

---

## `ls`
lists files in the current directory
- example: `ls`

---

## `mkdir`
creates a new folder
- example: `mkdir task2_files`

---

## `cd`
moves you into a directory
- example: `cd task2_files`

---

## `touch`
creates a new empty file
- example: `touch a.txt b.txt`

---

## `echo`
prints text, usually piped into a file
- example: `echo "hello world" > a.txt`

---

## `cat`
prints the contents of a file
- example: `cat a.txt`

---

## `cp`
copies a file
- example: `cp a.txt backup.txt`

---

## `mv`
moves or renames a file
- example: `mv b.txt b_renamed.txt`

---

## `rm`
deletes a file
- example: `rm backup.txt`

---

## `apt-get update`
syncs your local package list from the internet
- example: `sudo apt-get update`

---

## `apt-get install`
downloads and installs a package
- example: `sudo apt-get install htop -y`

---

## `apt-get remove`
uninstalls a package but keeps its config files
- example: `sudo apt-get remove htop`

---

## `apt-get purge`
uninstalls a package and deletes its config files too
- example: `sudo apt-get purge htop`

---

## `apt list --installed`
shows all packages currently installed
- example: `apt list --installed | grep htop`

---

## `sleep N &`
runs a do-nothing pause process in the background
- example: `sleep 120 &`

---

## `ps`
lists all running processes
- example: `ps > task4_process_list.txt`

---

## `which`
shows where an installed program lives on the system
- example: `which htop tmux`

---

## `python3 -m http.server`
spins up a simple web server on a port
- example: `python3 -m http.server 8080 &`

---

## `kill %N`
stops a background job by its job number
- example: `kill %3`

---

## `systemd-detect-virt`
tells you if you're in a VM and what kind (kvm, vmware, none…)
- example: `systemd-detect-virt > task6_virtualization_check.txt`

---

## `lscpu | grep -i hypervisor`
checks cpu info for hypervisor details
- example: `lscpu | grep -i hypervisor >> task6_virtualization_check.txt`

---

## `hostname`
prints the machine's name
- example: `hostname >> task6_virtualization_check.txt`

---

## Task 1 — OS Information

```bash
uname -a > task1_os_info.txt
lsb_release -a >> task1_os_info.txt
```

![task1](images/task1.png)

---

## Task 2 — File System Commands

```bash
touch a.txt b.txt
echo "hello world" > a.txt
cat a.txt
cp a.txt backup.txt
mv b.txt b_renamed.txt
rm backup.txt
```

![task2](images/task2.png)

---

## Task 3 — Package Management with APT

```bash
sudo apt-get update
sudo apt-get install <package> -y
apt list --installed | grep <package>
sudo apt-get remove <package>
sudo apt-get purge <package>
```

![task3](images/task3.png)

---

## Task 4 — Programs vs Processes

```bash
sleep 120 &
ps > task4_process_list.txt
```

![task4](images/task4.png)

---

## Task 5 — Installing Apps & Multitasking

```bash
sudo apt-get install htop tmux -y
which htop tmux > task5_app_verify.txt
sleep 500 &
sleep 600 &
python3 -m http.server 8080 &
ps > task5_multitasking.txt
kill %3
```

![task5](images/task5.png)

---

## Task 6 — Virtualization Detection

```bash
systemd-detect-virt > task6_virtualization_check.txt
lscpu | grep -i hypervisor >> task6_virtualization_check.txt
uname -r >> task6_virtualization_check.txt
hostname >> task6_virtualization_check.txt
```

![task6](images/task6.png)

---

## Repository Structure

```
lab1/
├── README.md
├── images/
│   ├── task1.png
│   ├── task2.png
│   ├── task3.png
│   ├── task4.png
│   ├── task5.png
│   └── task6.png
├── task1_os_info.txt
├── task2_file_commands.txt
├── task2_files/
│   ├── a.txt
│   └── b_renamed.txt
├── task3_apt_install.txt
├── task3_apt_purge.txt
├── task3_apt_remove.txt
├── task3_apt_update.txt
├── task3_config_after_purge.txt
├── task3_config_after_remove.txt
├── task3_verify_install.txt
├── task4_process_list.txt
├── task5_app_verify.txt
└── task6_virtualization_check.txt
```