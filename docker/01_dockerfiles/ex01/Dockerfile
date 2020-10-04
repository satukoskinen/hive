FROM debian:latest

RUN apt-get update && apt-get install -y wget bzip2

ARG INSTALL_URL=https://files.teamspeak-services.com/releases/server/3.12.1/teamspeak3-server_linux_amd64-3.12.1.tar.bz2
ARG WORK_DIR=teamspeak3-server_linux_amd64

RUN wget ${INSTALL_URL} -O - | tar xvj

WORKDIR /${WORK_DIR}

COPY teamspeak_server_start.sh .

RUN useradd --home-dir /${WORK_DIR} teamspeak3-user \
	&& chown teamspeak3-user:teamspeak3-user -R .

USER teamspeak3-user

RUN touch .ts3server_license_accepted

EXPOSE 9987/udp 30033 10011 10022 41144

CMD ["./teamspeak_server_start.sh"]
#CMD ["./ts3server_startscript.sh", "start", "serveradmin_password=password"]

