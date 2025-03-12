FROM ubuntu:latest
MAINTAINER MakRus1
RUN apt-get update && apt-get install -y dpkg
COPY package.deb /home/package.deb
WORKDIR /home
RUN dpkg -i package.deb
ENTRYPOINT ["factorial"]
