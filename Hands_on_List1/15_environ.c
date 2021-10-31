/* @author Praveen Reddy 
 * @date : 2021-09-14
 * @desc Environment variables - environ 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

    extern char **environ; //environ is extern variable which is a pointer to, an array of pointers to strings(character pointer)

    int i=0;

    while(environ[i]) //Last pointer contains NULL 
        printf("%s\n",environ[i++]);
 
    return 0;
}

/*  Output: 

    CLUTTER_IM_MODULE=xim
    LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
    LC_MEASUREMENT=en_US.UTF-8
    LESSCLOSE=/usr/bin/lesspipe %s %s
    LC_PAPER=en_US.UTF-8
    LC_MONETARY=en_US.UTF-8
    XDG_MENU_PREFIX=gnome-
    LANG=en_IN.UTF-8
    DISPLAY=:0
    GNOME_SHELL_SESSION_MODE=ubuntu
    COLORTERM=truecolor
    USERNAME=praveen
    XDG_VTNR=2
    SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
    S_COLORS=auto
    LC_NAME=en_US.UTF-8
    XDG_SESSION_ID=2
    USER=praveen
    DESKTOP_SESSION=ubuntu
    QT4_IM_MODULE=xim
    TEXTDOMAINDIR=/usr/share/locale/
    GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/6c1b7895_be07_4e64_b6aa_44d1a0a7f374
    PWD=/home/praveen/IIITB/Term 1/Software Systems/Lab Exercises
    HOME=/home/praveen
    TEXTDOMAIN=im-config
    SSH_AGENT_PID=1768
    QT_ACCESSIBILITY=1
    XDG_SESSION_TYPE=x11
    XDG_DATA_DIRS=/usr/share/ubuntu:/usr/local/share/:/usr/share/:/var/lib/snapd/desktop
    XDG_SESSION_DESKTOP=ubuntu
    LC_ADDRESS=en_US.UTF-8
    GJS_DEBUG_OUTPUT=stderr
    LC_NUMERIC=en_US.UTF-8
    GTK_MODULES=gail:atk-bridge
    PAPERSIZE=letter
    WINDOWPATH=2
    TERM=xterm-256color
    SHELL=/bin/bash
    VTE_VERSION=5202
    QT_IM_MODULE=ibus
    XMODIFIERS=@im=ibus
    IM_CONFIG_PHASE=2
    XDG_CURRENT_DESKTOP=ubuntu:GNOME
    GPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1
    GNOME_TERMINAL_SERVICE=:1.77
    XDG_SEAT=seat0
    SHLVL=1
    LANGUAGE=en_IN
    LC_TELEPHONE=en_US.UTF-8
    GDMSESSION=ubuntu
    GNOME_DESKTOP_SESSION_ID=this-is-deprecated
    LOGNAME=praveen
    DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
    XDG_RUNTIME_DIR=/run/user/1000
    XAUTHORITY=/run/user/1000/gdm/Xauthority
    XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
    PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
    LC_IDENTIFICATION=en_US.UTF-8
    GJS_DEBUG_TOPICS=JS ERROR;JS LOG
    SESSION_MANAGER=local/praveen-Inspiron-5590:@/tmp/.ICE-unix/1672,unix/praveen-Inspiron-5590:/tmp/.ICE-unix/1672
    LESSOPEN=| /usr/bin/lesspipe %s
    GTK_IM_MODULE=ibus
    LC_TIME=en_US.UTF-8
    _=./a.out
    OLDPWD=/home/praveen/IIITB/Term 1/Software Systems
*/