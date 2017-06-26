#ifndef FUNCOES_H
    #define FUNCOES_H

    #include "lista.h"

    long InserirInicioV(long *v, long tam, long el) {
        long contagem = 1;
        if(tam < 0)
            return ++contagem;

        for(long i = 0; i < (tam - 1); i++) {
            v[i+1] = v[i];
            contagem++;
        }

        v[0] = el;
        
        return ++contagem;
    }

    long InserirFimV(long *v, long tam, long n, long el) {
        long contagem = 1;
        if(tam < 0) 
            return ++contagem;

        v[n] = el;
        
        return ++contagem;
    }

    long InserirPosV(long *v, long tam, long pos, long el) {
        long contagem = 1;
        if((tam < 0) || (pos > tam))
            return ++contagem;

        for(long i = pos; i < (tam - 1); i++) {
            v[i+1] = v[i];
            contagem++;
        }

        v[pos] = el;
        
        return ++contagem;
    }

#endif