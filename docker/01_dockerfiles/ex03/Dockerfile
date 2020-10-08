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

RUN sed -i "s/^external_url.*$/external_url 'http:\/\/127.0.0.1'/" /etc/gitlab/gitlab.rb \
	&& sed -i "s/^.*grafana\['enable'\].*$/grafana['enable'] = false/" /etc/gitlab/gitlab.rb \
#	&& sed -i "s/unicorn\['worker_timeout'\] = 60/unicorn\['worker_timeout'\] = 300/g" /etc/gitlab/gitlab.rb

EXPOSE 80 443 22

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) \
	&& gitlab-ctl reconfigure && bash