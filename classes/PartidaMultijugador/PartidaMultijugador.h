

class PartidaMultijugador{
    private:
      bool transimitidaEnVivo;
      //Implementar arrau pseudoatributo de Usuario
    public:
       PartidaMultijugador(bool);
       bool getTransimitidaEnVivo();
       void setTransmitidaEnVivo(bool);
       float darTotalHorasParticipantes();
};