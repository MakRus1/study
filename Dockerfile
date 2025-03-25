FROM ubuntu:latest
MAINTAINER MakRus1
RUN apt-get update && apt-get install -y dpkg
COPY ..deb /home/..deb
WORKDIR /home
RUN dpkg -i ..deb

EXPOSE 8080
ENTRYPOINT ["factorial"]
