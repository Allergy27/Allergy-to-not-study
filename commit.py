import subprocess
import sys
from datetime import datetime

def run_command(command):
    """
    运行指定的 shell 命令，并返回执行结果。
    """
    try:
        result = subprocess.run(command, check=True, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        print(result.stdout)
        return result.stdout
    except subprocess.CalledProcessError as e:
        print(f"Error executing command: {e.stderr}")
        sys.exit(1)

def git_add():
    """
    执行 git add .
    """
    print("Staging changes...")
    run_command(["git", "add", "."])

def has_staged_changes():
    """
    检查是否有文件被暂存。
    """
    try:
        subprocess.run(["git", "diff", "--cached", "--quiet"], check=True)
        # 如果执行成功，说明没有暂存的更改
        return False
    except subprocess.CalledProcessError:
        # 如果执行失败，说明有暂存的更改
        return True

def git_commit(commit_message=None):
    """
    执行 git commit -m "message"
    如果没有提供 commit_message，则使用当前日期作为默认提交信息。
    """
    if not has_staged_changes():
        print("No changes to commit.")
        return

    if not commit_message:
        commit_message = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        print(f"No commit message provided, using default: {commit_message}")
    else:
        print(f"Using provided commit message: {commit_message}")

    run_command(["git", "commit", "-m", commit_message])

def git_push():
    """
    执行 git push
    """
    print("Pushing to remote repository...")
    run_command(["git", "push"])

if __name__ == "__main__":
    # 使用 input() 提示用户输入提交信息
    commit_message = input("请输入提交信息（默认为日期时间）：").strip()

    # 如果没有输入，则使用默认的日期时间作为提交信息
    if not commit_message:
        commit_message = None

    git_add()
    git_commit(commit_message)
    git_push()

    # 暂停等待用户按键（防止窗口自动关闭）
    input("操作完成，按任意键退出...")

