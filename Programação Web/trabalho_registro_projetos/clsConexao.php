<?php
class clsConexao {
    private static $instancia = null;
    private $conexao;

    private function __construct() {
        $this->conexao = new mysqli('localhost', 'root', '', 'bd_empresa');

        if ($this->conexao->connect_error) {
            die('Erro de conexão: ' . $this->conexao->connect_error);
        }
    }

    public static function getInstancia() {
        if (!self::$instancia) {
            self::$instancia = new clsConexao();
        }
        return self::$instancia;
    }

    private function detectarTipos($parametros) {
        $tipos = '';
        foreach ($parametros as $parametro) {
            if (is_int($parametro)) {
                $tipos .= 'i';
            } elseif (is_double($parametro) || is_float($parametro)) {
                $tipos .= 'd';
            } elseif (is_string($parametro)) {
                $tipos .= 's';
            } else {
                $tipos .= 'b';
            }
        }
        return $tipos;
    }
    
    public function executarConsulta($sql, $parametros = []) {
        $stmt = $this->conexao->prepare($sql);
    
        if (!empty($parametros)) {
            $tipos = $this->detectarTipos($parametros);
            $stmt->bind_param($tipos, ...$parametros);
        }
    
        $stmt->execute();
        return $stmt;
    }
}
?>