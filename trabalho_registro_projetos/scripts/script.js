function formatarMoeda(event) {
    var valor = event.target.value;
    valor = valor.replace(/\D/g, '');
    valor = valor.replace(/(\d)(\d{2})$/, '$1,$2');
    if (valor.length > 3) {
        valor = valor.replace(/(\d)(\d{3})(\d{1,2}$)/, '$1.$2,$3');
    }
    event.target.value = 'R$ ' + valor;
}
