{\rtf1\ansi\ansicpg1252\cocoartf2509
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fmodern\fcharset0 Courier;}
{\colortbl;\red255\green255\blue255;\red115\green0\blue2;\red245\green245\blue245;\red0\green0\blue0;
\red16\green121\blue2;\red0\green0\blue117;\red83\green85\blue2;\red11\green84\blue83;\red0\green0\blue0;
}
{\*\expandedcolortbl;;\cssrgb\c53333\c0\c0;\cssrgb\c96863\c96863\c96863;\cssrgb\c0\c0\c0;
\cssrgb\c0\c53333\c0;\cssrgb\c0\c0\c53333;\cssrgb\c40000\c40000\c0;\cssrgb\c0\c40000\c40000;\cssrgb\c0\c0\c0\c87059;
}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\sl260\partightenfactor0

\f0\fs22\fsmilli11400 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #include\cf4 \strokec4  \cf5 \strokec5 <iostream>\cf4 \strokec4 \
\pard\pardeftab720\sl260\partightenfactor0
\cf6 \strokec6 using\cf4 \strokec4  \cf6 \strokec6 namespace\cf4 \strokec4  std\cf7 \strokec7 ;\cf4 \strokec4 \
\cf6 \strokec6 int\cf4 \strokec4  gcd\cf7 \strokec7 (\cf6 \strokec6 int\cf4 \strokec4  a\cf7 \strokec7 ,\cf4 \strokec4  \cf6 \strokec6 int\cf4 \strokec4  b\cf7 \strokec7 )\cf4 \strokec4  \cf7 \strokec7 \{\cf4 \strokec4 \
   \cf6 \strokec6 if\cf4 \strokec4  \cf7 \strokec7 (\cf4 \strokec4 b \cf7 \strokec7 ==\cf4 \strokec4  \cf8 \strokec8 0\cf7 \strokec7 )\cf4 \strokec4 \
   \cf6 \strokec6 return\cf4 \strokec4  a\cf7 \strokec7 ;\cf4 \strokec4 \
   \cf6 \strokec6 return\cf4 \strokec4  gcd\cf7 \strokec7 (\cf4 \strokec4 b\cf7 \strokec7 ,\cf4 \strokec4  a \cf7 \strokec7 %\cf4 \strokec4  b\cf7 \strokec7 );\cf4 \strokec4 \
\pard\pardeftab720\sl260\partightenfactor0
\cf7 \strokec7 \}\cf4 \strokec4 \
\pard\pardeftab720\sl260\partightenfactor0
\cf6 \strokec6 int\cf4 \strokec4  main\cf7 \strokec7 ()\cf4 \strokec4  \cf7 \strokec7 \{\cf4 \strokec4 \
   \cf6 \strokec6 int\cf4 \strokec4  a \cf7 \strokec7 ,\cf4 \strokec4  b\cf7 \strokec7 ;\cf4 \strokec4 \
   cout\cf7 \strokec7 <<\cf5 \strokec5 "Enter the values of a and b: "\cf7 \strokec7 <<\cf4 \strokec4 endl\cf7 \strokec7 ;\cf4 \strokec4 \
   cin\cf7 \strokec7 >>\cf4 \strokec4 a\cf7 \strokec7 >>\cf4 \strokec4 b\cf7 \strokec7 ;\cf4 \strokec4 \
   cout\cf7 \strokec7 <<\cf5 \strokec5 "GCD of "\cf7 \strokec7 <<\cf4 \strokec4  a \cf7 \strokec7 <<\cf5 \strokec5 " and "\cf7 \strokec7 <<\cf4 \strokec4  b \cf7 \strokec7 <<\cf5 \strokec5 " is "\cf7 \strokec7 <<\cf4 \strokec4  gcd\cf7 \strokec7 (\cf4 \strokec4 a\cf7 \strokec7 ,\cf4 \strokec4  b\cf7 \strokec7 );\cf4 \strokec4 \
   \cf6 \strokec6 return\cf4 \strokec4  \cf8 \strokec8 0\cf7 \strokec7 ;\cf4 \strokec4 \
\pard\pardeftab720\sl260\partightenfactor0
\cf7 \strokec7 \}\cf9 \strokec9 \
}