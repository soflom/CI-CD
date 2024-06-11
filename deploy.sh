#!/bin/expect

spawn scp src/cat/s21_cat src/grep/s21_grep xeniamad@172.24.116.8:/usr/local/bin
expect -exact "\rxeniamad@172.24.116.8's password: "
send -- "1\r"
expect eof
