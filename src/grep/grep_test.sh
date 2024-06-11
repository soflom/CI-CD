#!/bin/bash

out1=s21_GrepTest.txt
out2=GrepTest.txt
num=0
pattern=the
pattern_file=pattern1.txt
file2=text8.txt

echo "----|Тесты по флагам для одного файла (кроме -f)|----"
for flag in e i v c l n h s o
do
    ((num++))
    echo "----------------------------------------"
    echo "Test  #$num  flags:  -$flag"
    echo "Template: $pattern"
    echo "----------------------------------------"
    for file in text1.txt text4.txt text8.txt
    do
        ./s21_grep -$flag $pattern $file > $out1
        grep -$flag $pattern $file > $out2
    done
    echo "Result:"
    diff -s $out1 $out2
done

echo "   "
echo "   "
echo "   "
echo "----|Тесты по флагам для нескольких файлов (кроме -f)|----"
for flag in e i v c l n h s
do
    ((num++))
    echo "----------------------------------------"
    echo "Test  #$num  flags:  -$flag"
    echo "Template: $pattern"
    echo "----------------------------------------"
    for file in text1.txt text4.txt
    do
        ./s21_grep -$flag $pattern $file $file2 > $out1
        grep -$flag $pattern $file $file2 > $out2
    done
    echo "Result:"
    diff -s $out1 $out2
done

echo "   "
echo "   "
echo "   "
echo "----|Тесты для одного файла -f|----"
for flag in f
do
    ((num++))
    echo "----------------------------------------"
    echo "Test  #$num  flags:  -$flag"
    echo "Template: $pattern_file"
    echo "----------------------------------------"
    for file in text1.txt text4.txt text8.txt
    do
        ./s21_grep -$flag pattern1.txt $file > $out1
        grep -$flag pattern1.txt $file > $out2
    done
    echo "Result:"
    diff -s $out1 $out2
done

echo "   "
echo "   "
echo "   "
echo "----|Тесты для нескольких файлов -f|----"
for flag in f
do
    ((num++))
    echo "----------------------------------------"
    echo "Test  #$num  flags:  -$flag"
    echo "Template: $pattern_file"
    echo "----------------------------------------"
        ./s21_grep -$flag pattern.txt $file $file2 > $out1
        grep -$flag pattern.txt $file $file2 > $out2
    echo "Result:"
    diff -s $out1 $out2
done
