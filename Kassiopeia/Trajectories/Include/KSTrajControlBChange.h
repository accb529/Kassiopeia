#ifndef Kassiopeia_KSTrajControlBChange_h_
#define Kassiopeia_KSTrajControlBChange_h_

#include "KSComponentTemplate.h"

#include "KSTrajExactTypes.h"
#include "KSTrajExactSpinTypes.h"
#include "KSTrajAdiabaticSpinTypes.h"
#include "KSTrajAdiabaticTypes.h"

namespace Kassiopeia
{

    class KSTrajControlBChange :
        public KSComponentTemplate< KSTrajControlBChange >,
        public KSTrajExactControl,
        public KSTrajExactSpinControl,
        public KSTrajAdiabaticSpinControl,
        public KSTrajAdiabaticControl
    {
        public:
            KSTrajControlBChange();
            KSTrajControlBChange( const KSTrajControlBChange& aCopy );
            KSTrajControlBChange* Clone() const;
            virtual ~KSTrajControlBChange();

        public:
            void Calculate( const KSTrajExactParticle& aParticle, double& aValue );
            void Check( const KSTrajExactParticle& anInitialParticle, const KSTrajExactParticle& aFinalParticle, const KSTrajExactError& anError, bool& aFlag );

            void Calculate( const KSTrajExactSpinParticle& aParticle, double& aValue );
            void Check( const KSTrajExactSpinParticle& anInitialParticle, const KSTrajExactSpinParticle& aFinalParticle, const KSTrajExactSpinError& anError, bool& aFlag );

            void Calculate( const KSTrajAdiabaticSpinParticle& aParticle, double& aValue );
            void Check( const KSTrajAdiabaticSpinParticle& anInitialParticle, const KSTrajAdiabaticSpinParticle& aFinalParticle, const KSTrajAdiabaticSpinError& anError, bool& aFlag );

            void Calculate( const KSTrajAdiabaticParticle& aParticle, double& aValue );
            void Check( const KSTrajAdiabaticParticle& anInitialParticle, const KSTrajAdiabaticParticle& aFinalParticle, const KSTrajAdiabaticError& anError, bool& aFlag );

        public:
            void SetFraction( const double& aFraction );

        private:
            double fFraction;
    };

    inline void KSTrajControlBChange::SetFraction( const double& aFraction )
    {
        fFraction = aFraction;
        return;
    }

}

#endif
