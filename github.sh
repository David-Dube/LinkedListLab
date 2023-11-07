mkdir -p .ssh 
echo "n" | ssh-keygen -t rsa -f .ssh/id_rsa -q -N "" > /dev/null
echo "Add the following to your github SSH keys (https://github.com/settings/keys):"
echo
cat .ssh/id_rsa.pub
echo
echo "Press enter when you have done so"
read
git config core.sshCommand 'ssh -i .ssh/id_rsa -o UserKnownHostsFile=.ssh/known_hosts'
echo "yes" | git fetch > /dev/null
echo "Done"