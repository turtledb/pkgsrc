# $NetBSD: Makefile,v 1.1.1.1 2011/12/17 17:18:55 taca Exp $

DISTNAME=	dm-adjust-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/datamapper/dm-adjust
COMMENT=	DataMapper plugin to increment and decrement properties
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
