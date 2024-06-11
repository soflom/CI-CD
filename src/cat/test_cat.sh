#!/bin/bash

echo "Compare CatTest.txt & s21_CatTest.txt -------- without flag"
cat text1.txt > CatTest.txt
./s21_cat text1.txt > s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat text2.txt >> CatTest.txt
./s21_cat text2.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat text3.txt >> CatTest.txt
./s21_cat text3.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat text4.txt >> CatTest.txt
./s21_cat text4.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat text5.txt >> CatTest.txt
./s21_cat text5.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat text6.txt >> CatTest.txt
./s21_cat text6.txt >> s21_CatTest.txt
diff -s CatTest.txt s21_CatTest.txt
echo "                                      "
echo "Compare CatTest.txt & s21_CatTest.txt -------- flag -n"
cat -n text1.txt > CatTest.txt
./s21_cat -n text1.txt > s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -n text2.txt >> CatTest.txt
./s21_cat -n text2.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -n text3.txt >> CatTest.txt
./s21_cat -n text3.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -n text4.txt >> CatTest.txt
./s21_cat -n text4.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -n text5.txt >> CatTest.txt
./s21_cat -n text5.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -n text6.txt >> CatTest.txt
./s21_cat -n text6.txt >> s21_CatTest.txt
diff -s CatTest.txt s21_CatTest.txt
echo "                                                      "
echo "Compare CatTest.txt & s21_CatTest.txt -------- flag -b"
cat -b text1.txt > CatTest.txt
./s21_cat -b text1.txt > s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -b text2.txt >> CatTest.txt
./s21_cat -b text2.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -b text3.txt >> CatTest.txt
./s21_cat -b text3.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -b text4.txt >> CatTest.txt
./s21_cat -b text4.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -b text5.txt >> CatTest.txt
./s21_cat -b text5.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -b text6.txt >> CatTest.txt
./s21_cat -b text6.txt >> s21_CatTest.txt
diff -s CatTest.txt s21_CatTest.txt
echo "                                                      "
echo "Compare CatTest.txt & s21_CatTest.txt -------- flag -v"
cat -v text1.txt > CatTest.txt
./s21_cat -v text1.txt > s21_CatTest.txt
diff  CatTest.txt s21_CatTest.txt
cat -v text2.txt >>CatTest.txt
./s21_cat -v text2.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -v text3.txt >> CatTest.txt
./s21_cat -v text3.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -v text4.txt >> CatTest.txt
./s21_cat -v text4.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -v text5.txt >> CatTest.txt
./s21_cat -v text5.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -v text6.txt >> CatTest.txt
./s21_cat -v text6.txt >> s21_CatTest.txt
diff -s CatTest.txt s21_CatTest.txt
echo "                                                      "
echo "Compare CatTest.txt & s21_CatTest.txt -------- flag -e"
cat -e text1.txt > CatTest.txt
./s21_cat -e text1.txt > s21_CatTest.txt
diff  CatTest.txt s21_CatTest.txt
cat -e text2.txt >>CatTest.txt
./s21_cat -e text2.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -e text3.txt >> CatTest.txt
./s21_cat -e text3.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -e text4.txt >> CatTest.txt
./s21_cat -e text4.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -e text5.txt >> CatTest.txt
./s21_cat -e text5.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -e text6.txt >> CatTest.txt
./s21_cat -e text6.txt >> s21_CatTest.txt
diff -s CatTest.txt s21_CatTest.txt
echo "                                                      "
echo "Compare CatTest.txt & s21_CatTest.txt -------- flag -t"
cat -t text1.txt > CatTest.txt
./s21_cat -t text1.txt > s21_CatTest.txt
diff  CatTest.txt s21_CatTest.txt
cat -t text2.txt >>CatTest.txt
./s21_cat -t text2.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -t text3.txt >> CatTest.txt
./s21_cat -t text3.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -t text4.txt >> CatTest.txt
./s21_cat -t text4.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -t text5.txt >> CatTest.txt
./s21_cat -t text5.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -t text6.txt >> CatTest.txt
./s21_cat -t text6.txt >> s21_CatTest.txt
diff -s CatTest.txt s21_CatTest.txt
echo "                                                      "
echo "Compare CatTest.txt & s21_CatTest.txt -------- flag -s"
cat -s text1.txt > CatTest.txt
./s21_cat -s text1.txt > s21_CatTest.txt
diff  CatTest.txt s21_CatTest.txt
cat -s text2.txt >>CatTest.txt
./s21_cat -s text2.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -s text3.txt >> CatTest.txt
./s21_cat -s text3.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -s text4.txt >> CatTest.txt
./s21_cat -s text4.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -s text5.txt >> CatTest.txt
./s21_cat -s text5.txt >> s21_CatTest.txt
diff CatTest.txt s21_CatTest.txt
cat -s text6.txt >> CatTest.txt
./s21_cat -s text6.txt >> s21_CatTest.txt
diff -s CatTest.txt s21_CatTest.txt

echo "DONE"