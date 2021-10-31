/* @author Praveen Reddy 
 * @date : 2021-09-03
 * @desc Check Process related information in /proc directory
 */

#include<stdio.h>

int main(){

	while(1); /* send this program execution to background using & while running, use /proc/pid/status */

	return 0;
}

/*  Output:

    Name: a.out
    Umask:  0002
    State:  R (running)
    Tgid:   14606
    Ngid:   0
    Pid:    14606
    PPid:   6624
    TracerPid:  0
    Uid:    1000    1000    1000    1000
    Gid:    1000    1000    1000    1000
    FDSize: 256
    Groups: 4 24 27 30 46 116 126 1000 
    NStgid: 14606
    NSpid:  14606
    NSpgid: 14606
    NSsid:  6624
    VmPeak:     4464 kB
    VmSize:     4380 kB
    VmLck:         0 kB
    VmPin:         0 kB
    VmHWM:       804 kB
    VmRSS:       804 kB
    RssAnon:          64 kB
    RssFile:         740 kB
    RssShmem:          0 kB
    VmData:       44 kB
    VmStk:       132 kB
    VmExe:         4 kB
    VmLib:      2116 kB
    VmPTE:        44 kB
    VmSwap:        0 kB
    HugetlbPages:          0 kB
    CoreDumping:    0
    THP_enabled:    1
    Threads:    1
    SigQ:   0/30791
    SigPnd: 0000000000000000
    ShdPnd: 0000000000000000
    SigBlk: 0000000000000000
    SigIgn: 0000000000000000
    SigCgt: 0000000000000000
    CapInh: 0000000000000000
    CapPrm: 0000000000000000
    CapEff: 0000000000000000
    CapBnd: 0000003fffffffff
    CapAmb: 0000000000000000
    NoNewPrivs: 0
    Seccomp:    0
    Speculation_Store_Bypass:   thread vulnerable
    Cpus_allowed:   ff
    Cpus_allowed_list:  0-7
    Mems_allowed:   00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
    Mems_allowed_list:  0
    voluntary_ctxt_switches:    0
    nonvoluntary_ctxt_switches: 214

*/