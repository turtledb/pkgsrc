$NetBSD$

Fix endianness detection on SunOS/x86_64.
--- lib/py/src/protocol/fastbinary.c.orig	2011-08-11 13:19:11.000000000 +0000
+++ lib/py/src/protocol/fastbinary.c
@@ -37,7 +37,7 @@
  #endif
 
  /* I386 is LE, even on Solaris */
- #if !defined(BYTE_ORDER) && defined(__i386__)
+ #if !defined(BYTE_ORDER) && ( defined(__i386__) || defined(__x86_64__) )
   #define BYTE_ORDER LITTLE_ENDIAN
  #endif
 #endif
