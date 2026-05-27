class IControladorReserva{
  public:
  virtual std::list<std::string> listarUsuarios()=0;
  virtual std::set<DTConsultaViaje> consultarViajes(DTFecha fecha,std::string origen,std::string destino,int asientos) =0;
  virtual bool generarReserva (std::string nickname,int codigo,int asientos) = 0;
}