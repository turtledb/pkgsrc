# $NetBSD: Makefile,v 1.96 2013/11/30 22:28:41 tsutsui Exp $

DISTNAME=	mlterm-3.3.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mlterm/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://mlterm.sourceforge.net/
COMMENT=	Multilingual terminal emulator
LICENSE=	modified-bsd

# CODESET is only supported on NetBSD in 1.5T and later - see <langinfo.h>
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-* NetBSD-1.5[A-S]-*

USE_TOOLS+=		pkg-config msgfmt
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

PKG_SYSCONFSUBDIR=	mlterm
EGDIR=			${PREFIX}/share/examples/mlterm
.for f in aafont color font key main menu taafont termcap tfont vaafont vfont \
	xim
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

CONFIGURE_ARGS+=	--with-imagelib=gdk-pixbuf
CONFIGURE_ARGS+=	--without-libiconv-prefix
CONFIGURE_ARGS+=	--without-libintl-prefix
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

SUBST_CLASSES+=		link
SUBST_MESSAGE.link=	Fixing hardcoded paths and link options in Makefiles.
SUBST_STAGE.link=	post-patch
SUBST_FILES.link=	Makefile.in */Makefile.in */*/Makefile.in \
			*/*/*/Makefile.in
SUBST_SED.link=		-e 's|(LIBTOOL_LINK).*(LIBS)|& ${X11_LDFLAGS:M*:Q}|g'
SUBST_SED.link+=	-e 's|(LIBTOOL_LINK).*(LIBDIR)|& ${X11_LDFLAGS:M*:Q}|g'
SUBST_SED.link+=	-e 's|/usr/local/|${PREFIX}/|g'
SUBST_SED.link+=	-e 's|/usr/X11R7/|${X11BASE}/|g'

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Fixing hardcoded paths in man pages.
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	man/mlterm.1
SUBST_SED.man=		-e 's|/usr/X11R6/lib/X11/mlterm/|${PKG_SYSCONFDIR}/|g'
SUBST_SED.man+=		-e 's|/usr/X11R6/include/|${X11BASE}/include/|g'

SUBST_CLASSES+=		conf
SUBST_MESSAGE.conf=	Fixing hardcoded paths in config files.
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	etc/font-fb
SUBST_SED.conf=		-e 's|/usr/X11R7/|${X11BASE}/|g'
SUBST_SED.conf+=	-e 's|/usr/pkg/|${PREFIX}/|g'

BUILDLINK_DEPMETHOD.libXt?=	build

INSTALLATION_DIRS=	share/doc/mlterm share/doc/mlterm/en share/doc/mlterm/ja

post-install:
.for f in FAQ PROTOCOL README.bidi README.fb README.indic README.xim
	${INSTALL_DATA} ${WRKSRC}/doc/en/${f} \
		${DESTDIR}${PREFIX}/share/doc/mlterm/en
.endfor
.for f in BUGS FAQ README.aafont README.comb README.confapp README.fb \
		README.fontproto README.ja README.pty README.server \
		README.tate README.utf8 README.xim
	${INSTALL_DATA} ${WRKSRC}/doc/ja/${f} \
		${DESTDIR}${PREFIX}/share/doc/mlterm/ja
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
