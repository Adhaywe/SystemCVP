//
// Created by adam on 22.02.24.
//

# include <systemc.h>
#include <iostream>

SC_MODULE(rslatch) {
      sc_in<bool> s;
      sc_in<bool> r;
      sc_out<bool> n;
      sc_out<bool> q;

      SC_CTOR(rslatch) : s("s"), r("r"), n("n"), q("q")
    {
          SC_METHOD(process);
          sensitive << s << r << n << q;
    }

    void process() {
          n.write (!(s.read() || q.read()));
          q.write (!(r.read() || n.read()));
      }
};

SC_MODULE(toplevel) {
    sc_signal<bool> S;
    sc_signal<bool> R;
    sc_signal<bool> N;
    sc_signal<bool> Q;

    rslatch rs;

    SC_CTOR(toplevel) : rs("rs")
    {
        SC_THREAD(stimuli);

        //do binding
        rs.s.bind(S);
        rs.r.bind(R);
        rs.n.bind(N);
        rs.q.bind(Q);

        S.write(false);
        R.write(true);
        N.write(true);
        Q.write(false);
    }

    void stimuli() {
        R.write(false);
        S.write(true);

        wait(10, SC_NS);

        std::cout << "n : " << N.read() << " q : " << Q.read() << std::endl;



        R.write(true);
        S.write(true);

        wait (10, SC_NS);

        std::cout << "n : " << N.read() << " q : " << Q.read() << std::endl;


    }
};


int sc_main(int, char**) {
    toplevel tp("tp");

    sc_start();

    return 0;
}