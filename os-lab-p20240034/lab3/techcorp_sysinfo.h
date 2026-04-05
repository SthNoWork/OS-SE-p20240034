#ifndef TECHCORP_SYSINFO_H
#define TECHCORP_SYSINFO_H

// Returns the hostname of the machine
const char* tc_get_hostname(void);

// Returns the current uptime in a human-readable string
const char* tc_get_uptime(void);

// Returns the number of CPU cores
int tc_get_cpu_count(void);

#endif
