FROM ubuntu:18.04

RUN apt-get update && apt-get install -y \
	ca-certificates \
	curl \
	openssh-server \
	mailutils \
	tzdata \
	&& apt-get autoclean

WORKDIR /tmp

RUN curl -s https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash

RUN apt-get install -y gitlab-ce

ARG IP=192.168.99.105

RUN sed -i "s/^external_url.*$/external_url 'https:\/\/$IP'/" /etc/gitlab/gitlab.rb \
	&& sed -i "s/^.*grafana\['enable'\].*$/grafana['enable'] = false/" /etc/gitlab/gitlab.rb \
	&& sed -i "s/^.*gitlab_rails\['gitlab_shell_ssh_port'\] = 22.*$/gitlab_rails['gitlab_shell_ssh_port'] = 2222/" /etc/gitlab/gitlab.rb \
	&& sed -i "s/#Port 22/Port 2222/" /etc/ssh/sshd_config

RUN mkdir -p /etc/gitlab/ssl \
	&& chmod 755 /etc/gitlab/ssl \
	&& openssl req -x509 -newkey rsa:4096 -sha256 -days 3650 -nodes \
	-keyout /etc/gitlab/ssl/$IP.key -out /etc/gitlab/ssl/$IP.crt \
	-subj "/CN=localhost" -addext "subjectAltName=IP:$IP"

EXPOSE 80 443 2222

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) \
	&& gitlab-ctl reconfigure && service ssh start && tail -f /dev/null

