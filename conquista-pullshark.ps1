
$ErrorActionPreference = "Stop"

Write-Host "`n=== AUTOMATIZADOR PULL SHARK ===" -ForegroundColor Cyan

# 1. Verificar autenticacao
gh auth status
if ($LASTEXITCODE -ne 0) {
    throw "Autenticacao do GitHub nao encontrada."
}

# 2. Identificar repositorio
$repo = gh repo view --json nameWithOwner --jq ".nameWithOwner"
if ($LASTEXITCODE -ne 0) {
    throw "Nao foi possivel identificar o repositorio."
}

if ($repo.Split("/")[-1] -ne "conquistas") {
    throw "Execute o script dentro do repositorio conquistas."
}

# 3. Identificar branch principal
$base = gh repo view --json defaultBranchRef --jq ".defaultBranchRef.name"
if ($LASTEXITCODE -ne 0) {
    throw "Nao foi possivel identificar a branch principal."
}

# 4. Identificar branch atual
$branch = git branch --show-current

if ($branch -eq $base) {
    throw "Crie uma branch propria antes de continuar."
}

if (-not $branch) {
    throw "Nenhuma branch ativa."
}

# 5. Verificar alteracoes pendentes
$alteracoes = git status --porcelain

if ($alteracoes) {
    Write-Host $alteracoes
    throw "Existem alteracoes nao commitadas."
}

# 6. Verificar commits novos
git fetch origin

if ($LASTEXITCODE -ne 0) {
    throw "Falha ao atualizar referencias remotas."
}

$commits = git rev-list --count "origin/$base..HEAD"

if ([int]$commits -le 0) {
    throw "Nao existem commits novos para enviar."
}

Write-Host "`nRepositorio: $repo"
Write-Host "Branch principal: $base"
Write-Host "Branch atual: $branch"
Write-Host "Commits novos: $commits"

# 7. Confirmar envio
$confirmacao = Read-Host "`nDeseja enviar a branch e criar o PR? (S/N)"

if ($confirmacao -ne "S") {
    Write-Host "Operacao cancelada."
    exit
}

# 8. Enviar branch
git push -u origin $branch

if ($LASTEXITCODE -ne 0) {
    throw "Falha ao enviar branch."
}

# 9. Criar Pull Request
gh pr create --base $base --head $branch --fill

if ($LASTEXITCODE -ne 0) {
    throw "Nao foi possivel criar o Pull Request."
}

# 10. Abrir PR
gh pr view --web

Write-Host "`nPull Request criado. Revise e faca o merge quando apropriado." -ForegroundColor Green
