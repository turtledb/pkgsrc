# $NetBSD: Makefile,v 1.8 2013/05/31 12:40:15 wiz Exp $

DISTNAME=	Devel-Events-Objects-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-Events-Objects/
COMMENT=	Perl 5 module providing object tracking support for Devel::Events

BUILD_DEPENDS+=	p5-Test-use-ok-[0-9]*:../../devel/p5-Test-use-ok
DEPENDS+=	p5-Devel-Events>=0.03:../../devel/p5-Devel-Events
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Tie-RefHash-Weak>=0.07:../../devel/p5-Tie-RefHash-Weak
DEPENDS+=	p5-Variable-Magic>=0.04:../../devel/p5-Variable-Magic

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/Events/Objects/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
