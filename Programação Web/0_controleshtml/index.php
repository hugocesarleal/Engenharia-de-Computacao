<html>
    <head>
        <title>
            Aula 0 - Controles HTML
        </title>
        <script>
            function alerta(){
                alert("Deu certo!")
            }
        </script>

    <link href="bootstrap.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    </head>

    <body>
        <!-- Formulario de cliente -->
        <form name="frmCadastro"
              action="processa.php"
              method="post"
              enctype="multipart/form-data">
            <input type="hidden" name="hddCodigo" value="Sadi Gostoso"/>
            
            <table border="1px" width="300px" cellspacing="4px" cellpadding="5px">
                <tr>
                    <td colspan="2">Cadastro de Cliente</td>
                </tr>

                <tr>
                    <td width="15%">Código:</td>
                    <td colspan="2" align="center">
                        <input type="text"
                               name="txtCodigo"
                               value="12346"
                               readonly="true"
                               size="100"/>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Nome:</td>
                    <td>
                        <input type="text"
                               name="txtNome"
                               value=""
                               placeholder="Insira seu nome"
                               size="100"
                               maxlength="80"/>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Senha:</td>
                    <td>
                        <input type="password"
                               name="txtSenha"
                               value="123456"
                               maxlength="6"
                               disabled="true"/>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Email:</td>
                    <td>
                        <input type="text"
                               name="txtEmail"
                               placeholder="Insira aqui o seu email"
                               size="100"/>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Data de Nascimento:</td>
                    <td>
                        <input type="date" name="txtDataNasc"/>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Carregue sua foto:</td>
                    <td>
                        <input type="file" name="txtArquivo"/>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Estado Civil:</td>
                    <td>
                        <input type="radio" name="rdbEstCivil" id="rdbCasado" value="1"/>
                        <label for="rdbCasado">Casado</label><br>
                        <input type="radio" name="rdbEstCivil" id="rdbSolteiro" value="2"/>
                        <label for="rdbSolteiro">Solteiro</label><br>
                        <input type="radio" name="rdbEstCivil" id="rdbEnrolado" value="3" checked="true"/>
                        <label for="rdbEnrolado">Enrolado</label><br>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Qual sua área de atuação:</td>
                    <td>
                        <input type="checkbox" name="chkEngenharias" value="engenharias"/> Engenharias <br>
                        <input type="checkbox" name="chkAgrarias" value="agrarias"/> Agrarias <br>
                        <input type="checkbox" name="chkHumanas" value="humanas"/> Humanas <br>
                        <input type="checkbox" name="chkLinguagens" value="linguagens"/> Linguagens <br>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Digite a sua mensagem:</td>
                    <td>
                        <textarea name="txaMensagem" rows="5" cols="60"></textarea>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Quanto voc&ecirc gosta do Sadi?</td>
                    <td>
                        <select name="slcSadi" size="1">
                            <option value="amo" selected="true">Amo</option>
                            <option value="suporto">Suporto</option>
                            <option value="ponte">Jogaria de uma ponte</option>
                        </select>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Qual sua cor favorita?</td>
                    <td>
                        
                        <input type="color" name="clrColor"/>
                            
                    </td>
                </tr>

                <tr>
                    <td width="15%">Selecione os itens da sua lista de compras:</td>
                    <td>
                        <select name="slcLista[]" size="9" multiple="true">
                            <optgroup label="Alimentos">
                                <option value="Biscoito">Biscoito</option>
                                <option value="Bolacha">Bolacha</option>
                            </optgroup>
                            <optgroup label="Higiene">
                                <option value="Sabonete">Sabonete</option>
                                <option value="Shampoo">Shampoo</option>
                            </optgroup>
                            <optgroup label="Frios">
                                <option value="Mussarela">Mussarela</option>
                                <option value="Presunto">Presunto</option>
                            </optgroup>
                        </select>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Nos dois grupos, selecione seu professor favorito:</td>
                    <td>
                        <fieldset>
                            <legend>Inteligência Artificial</legend>
                            <input type="radio" name="rdbIA" id="rdbCiniro1" value="Ciniro 1"/>
                            <label for="rdbCiniro1">Ciniro 1</label><br>
                            <input type="radio" name="rdbIA" id="rdbCiniro2" value="Ciniro 2"/>
                            <label for="rdbCiniro2">Ciniro 2</label><br>
                        </fieldset>
                        <fieldset>
                            <legend>Programação Web</legend>
                            <input type="radio" name="rdbWeb" id="rdbCiniro3" value="Ciniro 3"/>
                            <label for="rdbCiniro3">Ciniro 3</label><br>
                            <input type="radio" name="rdbWeb" id="rdbCiniro4" value="Ciniro 4"/>
                            <label for="rdbCiniro4">Ciniro 4</label><br>
                        </fieldset>
                    </td>
                </tr>

                <tr>
                    <td width="15%">Controle de imagem:</td>
                    <td>
                        <input type="image" name="imgImagem" src="imagens/sadi.jpg" alt="Sadi Feliz" value="fotoSadi" onclick="alerta()" width="50%" height="50%"/>
                        <br>
                        <label for="imgImagem">Meu amigo Sadi fazendo aniversário!</label>
                    </td>
                </tr>

                <tr>
                    <td colspan="2">
                        <input type="reset" name="btnLimpar" value="Limpar"/>
                        <input type="submit" name="btnSalvar" value="Salvar"/>
                    </td>
                </tr>
            </table>
        </form>
    </body>
</html>
