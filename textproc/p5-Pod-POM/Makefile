# $NetBSD: Makefile,v 1.27 2013/09/05 19:49:39 wiz Exp $

DISTNAME=	Pod-POM-0.28
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pod
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-POM/
COMMENT=	P5 module to format POD into an object format, hence POM
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Pod/POM/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
