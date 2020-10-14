#### Build stage ####

# Use debian as parent image
FROM ruby:2.7.2 AS builder

# To install yarn properly
RUN curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | apt-key add - \
	&& echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list

# Install packages needed for this rails application
RUN apt-get update \
	&& apt-get install -y \
	nodejs \
	sqlite3 \
	rails \
	yarn
#	&& rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /opt/app

# Copy and install Ruby dependencies
COPY Gemfile Gemfile.lock ./
RUN gem update bundler && \
	bundle install

# Copy and install JavaScript dependencies
COPY package.json yarn.lock ./
RUN yarn install --check-files

# Copy source code
COPY . .

# Database migration
RUN rails db:migrate

# Remove some unneeded files
RUN rm -rf node_modules tmp/cache /usr/local/bundle/cache/*.gem \
	vendor/assets spec


#### Final image ####

FROM ruby:2.7.2

RUN apt-get update \
	&& apt-get install -y \
	nodejs \
	sqlite3 \
	yarn \
	rails

# Create a non-root user for running the application
RUN useradd -d /opt/app --create-home -U rails-user
USER rails-user

# Copy files needed for running the application
COPY --from=builder /usr/local/bundle /usr/local/bundle
COPY --from=builder --chown=rails-user /opt/app /opt/app

WORKDIR /opt/app


