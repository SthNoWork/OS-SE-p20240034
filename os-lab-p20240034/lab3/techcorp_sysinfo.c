#include "techcorp_sysinfo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char hostname_buf[256];
static char uptime_buf[128];

const char* tc_get_hostname(void) {
    if (gethostname(hostname_buf, sizeof(hostname_buf)) == 0)
        return hostname_buf;
    return "unknown";
}

const char* tc_get_uptime(void) {
    FILE *fp = fopen("/proc/uptime", "r");
    if (fp) {
        double up_seconds;
        if (fscanf(fp, "%lf", &up_seconds) == 1) {
            int hours = (int)(up_seconds / 3600);
            int minutes = ((int)up_seconds % 3600) / 60;
            snprintf(uptime_buf, sizeof(uptime_buf),
                     "%d hours, %d minutes", hours, minutes);
        }
        fclose(fp);
        return uptime_buf;
    }
    return "unknown";
}

int tc_get_cpu_count(void) {
    return (int)sysconf(_SC_NPROCESSORS_ONLN);
}
