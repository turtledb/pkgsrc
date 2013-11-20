$NetBSD$

Fix segfaults when all servers are busy. From:

http://haproxy.1wt.eu/git?p=haproxy-1.4.git;h=d362dc75f3dfa7062e5c2cb7822ad12ffb755389

--- src/session.c.orig	2013-06-17 13:28:14.000000000 +0000
+++ src/session.c
@@ -1428,9 +1428,9 @@ resync_stream_interface:
 		/* Now we can add the server name to a header (if requested) */
 		/* check for HTTP mode and proxy server_name_hdr_name != NULL */
 		if ((s->flags & SN_BE_ASSIGNED) &&
-			(s->be->mode == PR_MODE_HTTP) &&
-			(s->be->server_id_hdr_name != NULL)) {
-
+		    (s->be->mode == PR_MODE_HTTP) &&
+		    (s->be->server_id_hdr_name != NULL) &&
+		    (s->srv)) {
 			http_send_name_header(&s->txn,
 					      &s->txn.req,
 					      s->req,
