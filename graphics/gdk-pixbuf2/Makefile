# $NetBSD: Makefile,v 1.27 2013/08/26 14:38:56 richard Exp $

DISTNAME=	gdk-pixbuf-${PIXBUF2_VERSION}
PKGNAME=	${DISTNAME:S/pixbuf/pixbuf2/}
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdk-pixbuf/${MSITE_VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.gnome.org/
COMMENT=	Image loaders for gtk2
LICENSE=	gnu-gpl-v2

CONFLICTS+=	gtk2+<2.22

.include "../../graphics/gdk-pixbuf2/Makefile.version"

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	contrib/gdk-pixbuf-xlib/gdk-pixbuf-xlib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gdk-pixbuf-2.0.pc.in

_BUILDING_GTK2= yes
.include "loaders.mk"

# We remove the loader database during post-install since we create it
# anew in the +INSTALL script as part of the POST-INSTALL action.
#
post-install:
	${RM} -f ${DESTDIR}${GDK_PIXBUF_LOADERS_DB}

BUILDLINK_API_DEPENDS.glib2+= glib2>=2.32.1
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
