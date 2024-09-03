FROM alpine:latest

ADD dist/oomer /app/oomer

CMD [ "/app/oomer" ]